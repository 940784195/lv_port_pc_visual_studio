﻿/*
 * PROJECT:   LVGL Windows Simulator
 * FILE:      LvglWindowsSimulator.cpp
 * PURPOSE:   Implementation for LVGL Windows Simulator
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <Windows.h>

#include <LvglWindowsIconResource.h>

#if _MSC_VER >= 1200
 // Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable:4244)
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"

#include "win32drv.h"

#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif

bool single_display_mode_initialization()
{
    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        800,
        480,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL_WINDOWS))))
    {
        return false;
    }

    lv_win32_add_all_input_devices_to_group(NULL);

    return true;
}

int main()
{
    lv_init();

    if (!single_display_mode_initialization())
    {
        return -1;
    }

    //lv_demo_widgets();
    lv_demo_benchmark(LV_DEMO_BENCHMARK_MODE_RENDER_AND_DRIVER);
    //C:\Users\94078\source\repos\940784195\lv_port_pc_visual_studio\LvglPlatform\lvgl\demos\benchmark\lv_demo_benchmark.c

    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        Sleep(1);
    }

    return 0;
}
