//  Graham Scan Algorithm for Convex Hull
//
//  Created by Steve DengZishi on 4/29/17.
//  Copyright © 2017 Steve DengZishi. All rights reserved.
//
//  1. Anchor point P0 is the one with lowest y coordinates (leftmost if tied)
//  2. Sort by polar angles (counter clockwise order)
//  3. Push points on to the stack
//  4. Pop the point if not on the hull
