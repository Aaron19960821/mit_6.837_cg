#ifndef CURVE_H
#define CURVE_H


#include "tuple.h"
#include <vector>
#include "../vecmath/include/vecmath.h"

// The CurvePoint object stores information about a point on a curve
// after it has been tesselated: the vertex (V), the tangent (T), the
// normal (N), and the binormal (B).  It is the responsiblility of
// functions that create these objects to fill in all the data.
struct CurvePoint
{
    Vector3f V; // Vertex
    Vector3f T; // Tangent  (unit)
    Vector3f N; // Normal   (unit)
    Vector3f B; // Binormal (unit)
};

// This is just a handy shortcut.
typedef std::vector< CurvePoint > Curve;


////////////////////////////////////////////////////////////////////////////
// The following two functions take an array of control points (stored
// in P) and generate an STL Vector of CurvePoints.  They should
// return an empty array if the number of control points in C is
// inconsistent with the type of curve.  In both these functions,
// "step" indicates the number of samples PER PIECE.  E.g., a
// 7-control-point Bezier curve will have two pieces (and the 4th
// control point is shared).
////////////////////////////////////////////////////////////////////////////

// Assume number of control points properly specifies a piecewise
// Bezier curve.  I.e., C.size() == 4 + 3*n, n=0,1,...
Curve evalBezier( const std::vector< Vector3f >& P, unsigned steps );

// Bsplines only require that there are at least 4 control points.
Curve evalBspline( const std::vector< Vector3f >& P, unsigned steps );

// Catmull-Rom spline needs at least 4 control points.
Curve evalCatmullRom( const std::vector< Vector3f >& P, unsigned steps, float tension);

// Create a circle on the xy-plane of radius and steps
Curve evalCircle( float radius, unsigned steps);


// Draw the curve and (optionally) the associated coordinate frames
// If framesize == 0, then no frames are drawn.  Otherwise, drawn.
void drawCurve( const Curve& curve, float framesize = 0 );

#endif