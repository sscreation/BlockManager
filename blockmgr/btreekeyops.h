/*
    Copyright (C) 2013 Sridhar Valaguru <sridharnitt@gmail.com>

    This file is part of BlockMgr.

    eXTendDB is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BlockMgr is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BlockMgr.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __B_TREE_KEY_OPS_H__
#define __B_TREE_KEY_OPS_H__
#include "stringutil.h"

typedef BinaryStr BTreeKey;
/*typedef struct BTreeValue {
   int value;
}BTreeValue;*/

typedef BinaryStr BTreeValue;

typedef int (*BTreeKeyCompareFn)(BTreeKey *key1,BTreeKey* key2);
typedef void (*BTreeKeyPrintFn)(BTreeKey* key);
typedef uint8_t (*BTreeKeyCopyFn)(BTreeKey* dst,BTreeKey* src,uint8_t new);

typedef void (*BTreeKeyFreeFn)(BTreeKey* key);

struct BTreeNode;

typedef struct BTreeKeyOps {
   BTreeKeyCompareFn cmp;
   BTreeKeyPrintFn print;
   BTreeKeyCopyFn copy;
   BTreeKeyFreeFn free;
}BTreeKeyOps;

#define BTreeKeyCmp(tree,k1,k2) tree->keyOps.cmp(k1,k2)
#define BTreeKeyFree(tree,key) tree->keyOps.free(key)
#define BTreeKeyCopy(tree,dst,src,new) tree->keyOps.copy(dst,src,new)
#define BTreeKeyPrint(tree,key) tree->keyOps.print(key)


void BTreeKeyIntPrint(BTreeKey* key);
int BTreeKeyBStrCmp(BTreeKey* key1,BTreeKey* key2);
int BTreeKeyOidCmp(BTreeKey* k1,BTreeKey* k2);
void BTreeKeyBStrPrint(BTreeKey* key);
void BTreeKeyStrPrint(BTreeKey* key);
uint8_t BTreeKeyBStrCopy(BTreeKey* dst,BTreeKey* src,uint8_t new);

void BTreeKeyBStrFree(BTreeKey* key);
int BTreeKeyIntCmp(BTreeKey* k1,BTreeKey* k2);
int BTreeKeyRangeCmp(BTreeKey* key1,BTreeKey* key2);

typedef struct LongRange {
   uint64_t start;
   uint64_t end;
}LongRange;
#endif
