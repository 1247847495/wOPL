/*
 * Manage cheat codes
 *
 * Copyright (C) 2009-2010 Mathias Lafeldt <misfire@debugon.org>
 * Copyright (C) 2014 doctorxyz
 *
 * This file is part of PS2rd, the PS2 remote debugger.
 *
 * PS2rd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PS2rd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PS2rd.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $Id$
 */

#ifndef _CHEATMAN_H_
#define _CHEATMAN_H_

#include <tamtypes.h>
#include "config.h"

#define CHEAT_NAME_MAX 128  // 这个本来就够大
#define CHEAT_VERSION "0.5.3.7"

#define MAX_HOOKS      5
#define MAX_CODES      250
#define MAX_CHEATLIST  (MAX_HOOKS * 2 + MAX_CODES * 2)
#define CHEAT_NAME_MAX 128

/* Some character defines */
#define NUL         0x00
#define LF          0x0A
#define CR          0x0D
#define SPACE       0x20
/* Number of digits per cheat code */
#define CODE_DIGITS 16

/**
 * code_t - a code object
 * @addr: code address
 * @val: code value
 */
typedef struct
{
    u32 addr;
    u32 val;
} code_t;

typedef struct
{
    char name[CHEAT_NAME_MAX + 1];
    code_t codes[MAX_CHEATLIST];
    int enabled;
} cheat_entry_t;

extern cheat_entry_t gCheats[MAX_CODES];
extern int gCheatSource;

void InitCheatsConfig(config_set_t *configSet);
int GetCheatsEnabled(void);
u32 *GetCheatsList(void);
int load_cheats(const char *cheatfile);
void set_cheats_list(void);

#endif /* _CHEATMAN_H_ */
// 清除所有作弊（你要的删除功能）
void ClearAllCheats(void);

// 清除单个作弊
void ClearSingleCheat(int index);

// 判断作弊名称是否是中文（可用于界面显示判断）
int IsChineseChar(const char *str);

// 获取作弊名称（支持UTF8中文）
const char *GetCheatName(int index);

// 检查某个作弊是否启用
int IsCheatEnabled(int index);

// 启用/禁用单个作弊
void EnableSingleCheat(int index, int enable);
