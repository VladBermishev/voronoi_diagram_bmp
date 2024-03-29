// SplashGeom (c) - open-source C++ library for geometry and linear algebra.
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
	along with SplashGeom. If not, see <http://www.gnu.org/licenses/>.
*/
#include "dcel.hpp"

namespace VoronoiDiagram {
    DCEL::DCEL()
            : edges() {}

    EdgeNode::EdgeNode()
            : edge_(), twin_(nullptr), site_(nullptr), finished_(false) {}

    EdgeNode::EdgeNode(const Point2D &p1, const Point2D &site) {
        edge_.a = p1;
        twin_ = nullptr;
        site_ = make_shared<Point2D>(site);
        finished_ = false;
    }

    EdgeNode::EdgeNode(const Point2D &p1, const Point2D &p2, const Point2D &site)
            : edge_(p1, p2), twin_(make_shared<EdgeNode>(p2, p1)), site_(make_shared<Point2D>(site)), finished_(true) {}

    void EdgeNode::Finish(const Point2D &end_point) {
        edge_.b = end_point;
        twin_ = make_shared<EdgeNode>(edge_.b, edge_.a);
        finished_ = true;
    }

    std::ostream &operator<<(std::ostream &out_stream, const EdgeNode &edge_node) {
        out_stream << edge_node.edge_.a << ' -> ' << edge_node.edge_.b;
        return out_stream;
    }

    void DCEL::AddEdge(const EdgeNode &new_edge) {
        edges.push_back(new_edge);
    }

    void DCEL::Finish(const Rectangle &border_box) {
        for (auto i : edges) {
            if (i.finished_ == false) {
                // pointer to the arc
            }
        }
    }
}