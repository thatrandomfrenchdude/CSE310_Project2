//
//  util.hpp
//  Project02
//
//  Created by Nicholas Debeurre on 3/21/17.
//  Copyright © 2017 Samoji. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <stdio.h>

void heapify(Heap *heap, int i);
int parent(int i);
int left(int i);
int right(int i);

#endif /* util_hpp */
