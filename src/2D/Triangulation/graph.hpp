// SplashGeom (c) - open-source C++ library for geometry and linear algebra
// Copyright (c) 2016, Ilya Zakharkin, Elena Kirilenko and Nadezhda Kasimova.
// All rights reserved.
/*
	This file is part of SplashGeom.

	SplashGeom is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	SplashGeom is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with SplashGeom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include "edge.hpp"
#include "vertex.hpp"

class DelaunayTriangulationBuilder;

class Graph {
public:
    std::vector<std::shared_ptr<Vertex>>::iterator add_vertex(const Point2D &point2D);

    std::vector<std::shared_ptr<Vertex>>::iterator add_vertex(Point2D &&point2D);

    // returns nullptr if such edge exists
    std::shared_ptr<Edge> add_edge(std::vector<std::shared_ptr<Vertex>>::iterator vertex1,
                                   std::vector<std::shared_ptr<Vertex>>::iterator vertex2);

    std::vector<std::shared_ptr<Vertex>> vertices;
    std::vector<std::shared_ptr<Edge>> edges;

private:
    friend class DelaunayTriangulationBuilder;

    static void print_all_neighbours(const std::shared_ptr<Vertex> &x);

    std::vector<std::shared_ptr<Vertex>> get_similar_vertices(std::shared_ptr<Vertex> x, std::shared_ptr<Vertex> y);
};


#endif /* graph_hpp */
