#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
批量替换反编译代码中的函数名
将已还原的函数名应用到代码中
"""

import os
import sys

# 定义函数名映射表
FUNCTION_MAPPINGS = {
    # 内存操作函数
    'FUN_rom_00f1a8': 'memset',
    'FUN_rom_008fb8': 'memzero',
    'FUN_rom_00d070': 'strcpy',
    'FUN_rom_009d72': 'memcpy',
    'FUN_rom_009462': 'smart_strcpy',
    'FUN_rom_00959c': 'smart_strcat',
    'FUN_rom_00b5ba': 'byte_strlen',
    
    # 显示相关函数
    'FUN_rom_007eac': 'fill_screen',
    'FUN_rom_007f00': 'buffer_clear',
    'FUN_rom_007f1a': 'set_display_line',
    'FUN_rom_007f58': 'set_display_position',
    'FUN_rom_007fa0': 'set_display_area',
    'FUN_rom_0086e0': 'buf1_to_buf2',
    'FUN_rom_0086f8': 'render_e3d4',
    'FUN_rom_008704': 'flush_screen',
    'FUN_rom_00a15a': 'refresh_display',
    
    # 字符打印函数
    'FUN_rom_0082ec': 'char_print_1byte',
    'FUN_rom_0082f6': 'char_print',
    'FUN_rom_0084d8': 'char_get_14',
    'FUN_rom_0085b8': 'char_get_l14',
    'FUN_rom_008c4a': 'line_print',
    'FUN_rom_008c6c': 'smallprint',
    'FUN_rom_008c88': 'line_print_col0',
    'FUN_rom_008c90': 'line_print_Col3',
    
    # 按键和延迟函数
    'FUN_rom_0096be': 'waitkey',
    'FUN_rom_0096fc': 'read_key',
    'FUN_rom_0094da': 'delay',
    
    # thunk函数（函数别名）
    'thunk_FUN_rom_00f1a8': 'thunk_memset',
    'thunk_FUN_rom_008fb8': 'thunk_memzero',
    'thunk_FUN_rom_00d070': 'thunk_strcpy',
    'thunk_FUN_rom_009d72': 'thunk_memcpy',
}

def replace_functions_in_file(file_path, backup=True):
    """
    在文件中批量替换函数名
    
    Args:
        file_path: 文件路径
        backup: 是否创建备份文件
    """
    print(f"正在处理文件: {file_path}")
    
    # 检查文件是否存在
    if not os.path.exists(file_path):
        print(f"错误: 文件不存在: {file_path}")
        return False
    
    # 创建备份
    if backup:
        backup_path = file_path + '.backup'
        if not os.path.exists(backup_path):
            print(f"创建备份文件: {backup_path}")
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
            with open(backup_path, 'w', encoding='utf-8') as f:
                f.write(content)
    
    # 读取文件内容
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"错误: 无法读取文件: {e}")
        return False
    
    # 统计替换次数
    replacement_counts = {}
    
    # 执行替换
    for old_name, new_name in FUNCTION_MAPPINGS.items():
        count = content.count(old_name)
        if count > 0:
            content = content.replace(old_name, new_name)
            replacement_counts[old_name] = count
            print(f"  {old_name} -> {new_name}: {count} 次替换")
    
    # 写回文件
    try:
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"成功写入文件: {file_path}")
    except Exception as e:
        print(f"错误: 无法写入文件: {e}")
        return False
    
    # 打印统计信息
    print("\n替换统计:")
    total = sum(replacement_counts.values())
    print(f"总共替换了 {total} 处")
    
    return True

def main():
    """主函数"""
    # 获取脚本所在目录
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # 目标文件路径
    target_file = os.path.join(script_dir, '反编译结果', '991CN X.c')
    
    print("=" * 60)
    print("Casio fx-991CN X 固件反编译函数名批量替换工具")
    print("=" * 60)
    print()
    
    # 执行替换
    success = replace_functions_in_file(target_file, backup=True)
    
    if success:
        print("\n✓ 函数名替换完成！")
        print("\n已还原的函数类别:")
        print("  - 内存操作函数: 7个")
        print("  - 显示相关函数: 9个")
        print("  - 字符打印函数: 8个")
        print("  - 按键和延迟函数: 3个")
        print("  - thunk函数: 4个")
        print("  总计: 31个函数")
    else:
        print("\n✗ 函数名替换失败！")
        sys.exit(1)

if __name__ == '__main__':
    main()
