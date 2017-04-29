//  Graham Scan Algorithm for Convex Hull
//
//  Created by Steve DengZishi on 4/29/17.
//  Copyright © 2017 Steve DengZishi. All rights reserved.
//
//  1. Anchor point P0 is the one with lowest y coordinates (leftmost if tied)
//  2. Sort by polar angles (counter clockwise order)
//  3. Check whether left turn to the point on top of stack
//  4. Push the point on to the stack if left turn
//  5. Pop the point if right turn & repeat the checking process (not on the hull)
//
//  Running time: O(nlogn) sorting + O(n) scanning  OVERALL O(nlogn)
