/****************************************************************************
** gmio benchmarks
** Copyright Fougue (2 Mar. 2015)
** contact@fougue.pro
**
** This software provides performance benchmarks for the gmio library
** (https://github.com/fougue/gmio)
**
** This software is governed by the CeCILL-B license under French law and
** abiding by the rules of distribution of free software.  You can  use,
** modify and/ or redistribute the software under the terms of the CeCILL-B
** license as circulated by CEA, CNRS and INRIA at the following URL
** "http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html".
****************************************************************************/

#include <OSD_Path.hxx>
#include <RWStl.hxx>
#include <StlMesh_Mesh.hxx>
#include <Standard_Version.hxx>

#include <gmio_core/error.h>
#include <gmio_stl/stl_io.h>
#include <gmio_stl/stl_io_options.h>
#include <gmio_support/stl_occ.h>

#include "../commons/benchmark_tools.h"

#include <vector>

namespace BmkOcc {

Handle_StlMesh_Mesh stlMesh;

static void RWStl_ReadFile(const char* filepath)
{
    stlMesh = RWStl::ReadFile(OSD_Path(filepath));
    if (stlMesh.IsNull())
        printf("RWStl::ReadFile(): null mesh\n");
}

static void RWStl_WriteAscii(const char* filepath)
{
    if (!RWStl::WriteAscii(stlMesh, OSD_Path(filepath)))
        printf("RWStl::WriteAscii() failure\n");
}

static void RWStl_WriteBinary(const char* filepath)
{
    if (!RWStl::WriteBinary(stlMesh, OSD_Path(filepath)))
        printf("RWStl::WriteBinary() failure\n");
}

} // namespace BmkOcc

namespace BmkGmio {

Handle_StlMesh_Mesh stlMesh;

static void stl_read(const char* filepath)
{
    stlMesh = new StlMesh_Mesh;
    gmio_stl_read_args read = {};
    args.mesh_creator = gmio_stl_hnd_occmesh_creator(stlMesh);
    int error = gmio_stl_read_file(&read, filepath);
    if (error != GMIO_ERROR_OK)
        printf("gmio error: 0x%X\n", error);
}

static void stl_write(const char* filepath, gmio_stl_format format)
{
    const gmio_occ_stl_mesh_domain occ_mesh_domain(stlMesh);
    gmio_stl_write_args write = {};
    write.format = format;
    write.mesh = gmio_stl_occmesh(&occ_mesh_domain);
    write.options.stla_float32_format = GMIO_FLOAT_TEXT_FORMAT_SHORTEST_UPPERCASE;
    write.options.stla_float32_prec = 7;
    const int error = gmio_stl_write_file(&write, filepath);
    if (error != GMIO_ERROR_OK)
        printf("gmio error: 0x%X\n", error);
}

static void stla_write(const char* filepath)
{
    stl_write(filepath, GMIO_STL_FORMAT_ASCII);
}

static void stlb_write_le(const char* filepath)
{
    stl_write(filepath, GMIO_STL_FORMAT_BINARY_LE);
}

static void stlb_write_be(const char* filepath)
{
    stl_write(filepath, GMIO_STL_FORMAT_BINARY_BE);
}

} // namespace BmkGmio

int main(int argc, char** argv)
{
    if (argc > 1) {
        const char* filepath = argv[1];
        std::cout << std::endl << "Input file: " << filepath << std::endl;

        /* Declare benchmarks */
        const benchmark_cmp_arg cmp_args[] = {
            { "read",
              BmkGmio::stl_read, filepath,
              BmkOcc::RWStl_ReadFile, filepath },
            { "write(ascii)",
              BmkGmio::stla_write, "__bmk_occ_gmio.stla",
              BmkOcc::RWStl_WriteAscii, "__bmk_occ.stla" },
            { "write(binary/le)",
              BmkGmio::stlb_write_le, "__bmk_occ_gmio.stlb_le",
              BmkOcc::RWStl_WriteBinary, "__bmk_occ.stlb_le" },
            { "write(binary/be)",
              BmkGmio::stlb_write_be, "__bmk_occ_gmio.stlb_be",
              NULL, NULL },
            {}
        };

        /* Execute benchmarks */
        std::vector<benchmark_cmp_result> cmp_res_vec;
        cmp_res_vec.resize(sizeof(cmp_args) / sizeof(benchmark_cmp_arg) - 1);
        benchmark_cmp_batch(5, &cmp_args[0], &cmp_res_vec[0], NULL, NULL);

        /* Print results */
        const benchmark_cmp_result_array res_array = {
            &cmp_res_vec.at(0), cmp_res_vec.size() };
        const benchmark_cmp_result_header header = {
            "gmio", "OpenCascade v"OCC_VERSION_COMPLETE };
        benchmark_print_results(
                    BENCHMARK_PRINT_FORMAT_MARKDOWN, header, res_array);
    }
    return 0;
}
