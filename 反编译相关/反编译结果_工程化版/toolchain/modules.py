#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""模块划分：每个函数按地址区间 + 标签归入一个模块。"""

# 显示模块（0x7E00-0x8CFF）
DISPLAY_TAGS = {'gfx', 'text', 'font', 'menu'}
# 诊断模块
DIAG_TAGS = {'diag'}

def module_of(addr, tags, name):
    if addr is None:
        return 'other'
    if 0x000000 <= addr < 0x010000:
        if addr < 0x000200:
            return 'boot/vectors'
        if addr < 0x001000:
            return 'boot/vectors'
        return 'boot'
    return 'core'
