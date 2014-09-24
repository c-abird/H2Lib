
/* ------------------------------------------------------------
   This is the file "factorizations.h" of the H2Lib package.
   All rights reserved, Steffen Boerm 2010
   ------------------------------------------------------------ */

/** @file factorizations.h
 *  @author Steffen B&ouml;rm
 */

#ifndef FACTORIZATIONS_H
#define FACTORIZATIONS_H

/** @defgroup factorizations factorizations
 *  @brief Triangular and orthogonal factorizations.
 *
 *  The @ref factorizations module covers triangular factorizations
 *  like the LR factorization (without pivoting), the Cholesky
 *  factorization and the LDL^* factorization, and the orthogonal
 *  QR factorization.
 *  @{ */

#include "amatrix.h"

/* ------------------------------------------------------------
   Diagonal matrices
   ------------------------------------------------------------ */

/** @brief Solve @f$A x = b@f$ and variants for a diagonal matrix @f$A@f$.
 *
 *  @param atrans Set if adjoint matrix should be used.
 *  @param a Diagonal matrix.
 *  @param x Right-hand side, gets overwritten by solution. */
HEADER_PREFIX void
diagsolve_amatrix_avector(bool atrans, pcamatrix a, pavector x);

/** @brief Solve @f$A X = B@f$ and variants for a diagonal
 *         matrix @f$A@f$.
 *
 *  @param atrans Set if @f$A@f$ has to be transposed.
 *  @param a Diagonal matrix.
 *  @param xtrans Set if @f$X@f$ and @f$B@f$ have to be transposed.
 *  @param x Right-hand side @f$B@f$, gets overwritten by solution @f$X@f$. */
HEADER_PREFIX void
diagsolve_amatrix_amatrix(bool atrans, pcamatrix a,
			  bool xtrans, pamatrix x);

/** @brief Evaluate @f$B = A X@f$ and variants for a diagonal
 *         matrix @f$A@f$.
 *
 *  @param atrans Set if @f$A@f$ has to be transposed.
 *  @param a Diagonal matrix.
 *  @param xtrans Set if @f$X@f$ and @f$B@f$ have to be transposed.
 *  @param x Right-hand side @f$B@f$, gets overwritten by solution @f$X@f$. */
HEADER_PREFIX void
diageval_amatrix_amatrix(bool atrans, pcamatrix a,
			 bool xtrans, pamatrix x);

/* ------------------------------------------------------------
   Triangular matrices
   ------------------------------------------------------------ */

/** @brief Solve @f$A x = b@f$ and variants for a lower triangular
 *         matrix @f$A@f$.
 *
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param atrans Set if @f$A^*@f$ should be used instead of @f$A@f$.
 *                In this case, @f$A@f$ has to be upper triangular.
 *  @param a Triangular matrix @f$A@f$.
 *  @param x Right-hand side @f$b@f$, gets overwritten by solution @f$x@f$.
 *
 *  @deprecated @ref triangularsolve_amatrix_avector should be used. */
HEADER_PREFIX void
lowersolve_amatrix_avector(bool aunit, bool atrans, pcamatrix a, pavector x);

/** @brief Solve @f$A x = b@f$ and variants for an upper triangular
 *         matrix @f$A@f$.
 *
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param atrans Set if @f$A^*@f$ should be used instead of @f$A@f$.
 *                In this case, @f$A@f$ has to be lower triangular.
 *  @param a Triangular matrix @f$A@f$.
 *  @param x Right-hand side @f$b@f$, gets overwritten by solution @f$x@f$.
 *
 *  @deprecated @ref triangularsolve_amatrix_avector should be used. */
HEADER_PREFIX void
uppersolve_amatrix_avector(bool aunit, bool atrans, pcamatrix a, pavector x);

/** @brief Solve @f$A x = b@f$ for a triangular matrix @f$A@f$.
 *
 *  @param alower Set if @f$A@f$ is lower triangular, otherwise it is
 *                assumed to be upper triangular.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *  @param aunit Set of @f$A@f$ has unit diagonal.
 *  @param a Triangular matrix @f$A@f$.
 *  @param x Right-hand side @f$b@f$, gets overwritten by solution @f$x@f$ */
HEADER_PREFIX void
triangularsolve_amatrix_avector(bool alower, bool atrans, bool aunit,
			pcamatrix a, pavector x);

/** @brief Solve @f$A X = B@f$ and variants for a lower triangular
 *         matrix @f$A@f$.
 *
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *  @param a Triangular matrix @f$A@f$.
 *  @param xtrans Set if @f$X^*@f$ and @f$B^*@f$ are to be used
 *         instead of @f$X@f$ and @f$B@f$.
 *  @param x Right-hand side @f$B@f$, gets overwritten by solution @f$X@f$.
 *
 *  @deprecated @ref triangularsolve_amatrix_amatrix should be used. */
HEADER_PREFIX void
lowersolve_amatrix_amatrix(bool aunit, bool atrans, pcamatrix a,
			   bool xtrans, pamatrix x);

/** @brief Solve @f$A X = B@f$ and variants for an upper triangular
 *         matrix @f$A@f$.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *  @param a Triangular matrix @f$A@f$.
 *  @param xtrans Set if @f$X^*@f$ and @f$B^*@f$ are to be used
 *         instead of @f$X@f$ and @f$B@f$.
 *  @param x Right-hand side @f$B@f$, gets overwritten by solution @f$X@f$.
 *
 *  @deprecated @ref triangularsolve_amatrix_amatrix should be used. */
HEADER_PREFIX void
uppersolve_amatrix_amatrix(bool aunit, bool atrans, pcamatrix a,
			   bool xtrans, pamatrix x);

/** @brief Solve @f$A X = B@f$ and variants for a triangular
 *         matrix @f$A@f$.
 *
 *  @param alower Set if @f$A@f$ is lower triangular, otherwise
 *         it is assumed to be upper triangular.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param a Triangular matrix @f$A@f$.
 *  @param x Right-hand side @f$B@f$, gets overwritten by solution @f$X@f$.
 *  @param xtrans Set if @f$X^*@f$ has to be used instead of @f$X@f$. */
HEADER_PREFIX void
triangularsolve_amatrix_amatrix(bool alower, bool atrans, bool aunit,
				pcamatrix a, bool xtrans, pamatrix x);

/** @brief Evaluate @f$b = A x@f$ for a lower triangular
 *         matrix @f$A@f$.
 *
 *  @param a Lower triangular matrix @f$A@f$.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param x Right-hand side vector @f$x@f$, gets overwritten by @f$b@f$.
 *
 *  @deprecated @ref triangulareval_amatrix_avector should be used. */
HEADER_PREFIX void
lowereval_amatrix_avector(pcamatrix a, bool aunit, pavector x);

/** @brief Evaluate @f$b = A x@f$ for an upper triangular
 *         matrix @f$A@f$.
 *
 *  @param a Upper triangular matri @f$A@f$.
 *  @param aunit Set if matrix @f$A@f$ has unit diagonal.
 *  @param x Right-hand side vector @f$x@f$, gets overwritten by @f$b@f$.
 *
 *  @deprecated @ref triangulareval_amatrix_avector should be used. */
HEADER_PREFIX void
uppereval_amatrix_avector(pcamatrix a, bool aunit, pavector x);

/** @brief Evaluate @f$b = A x@f$ for a triangular matrix @f$A@f$.
 *
 *  @param alower Set if @f$A@f$ is lower triangular, otherwise
 *         it is assumed to be upper triangular.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param a Triangular matrix @f$A@f$.
 *  @param x Right-hand side vector @f$x@f$, gets overwritten by @f$b@f$. */
HEADER_PREFIX void
triangulareval_amatrix_avector(bool alower, bool aunit, pcamatrix a, pavector x);

/** @brief Evaluate @f$B = A X@f$ and variants for a lower triangular
 *         matrix @f$A@f$.
 *
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *                In this case, @f$A@f$ has to be upper triangular.
 *  @param a Triangular matrix @f$A@f$.
 *  @param xtrans Set if @f$X^*@f$ and @f$B^*@f$ are to be used
 *         instead of @f$X@f$ and @f$B@f$.
 *  @param x Right-hand side matrix @f$X@f$, gets overwritten by @f$B@f$.
 *
 *  @deprecated @ref triangulareval_amatrix_amatrix should be used. */
HEADER_PREFIX void
lowereval_amatrix_amatrix(bool aunit, bool atrans, pcamatrix a,
			  bool xtrans, pamatrix x);

/** @brief Evaluate @f$B = A X@f$ and variants for an upper triangular
 *         matrix @f$A@f$.
 *
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *                In this case, @f$A@f$ has to be lower triangular.
 *  @param a Triangular matrix @f$A@f$.
 *  @param xtrans Set if @f$X^*@f$ and @f$B^*@f$ are to be used
 *         instead of @f$X@f$ and @f$B@f$.
 *  @param x Right-hand side matrix @f$X@f$, gets overwritten by @f$B@f$.
 *
 *  @deprecated @ref triangulareval_amatrix_amatrix should be used. */
HEADER_PREFIX void
uppereval_amatrix_amatrix(bool aunit, bool atrans, pcamatrix a,
			  bool xtrans, pamatrix x);

/** @brief Evaluate @f$B = A X@f$ and variants for a triangular
 *         matrix @f$A@f$.
 *
 *  @param alower Set if @f$A@f$ is lower triangular, otherwise
 *         it is assumed to be upper triangular.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param a Triangular matrix @f$A@f$.
 *  @param xtrans Set if @f$X^*@f$ and @f$B^*@f$ are to be used
 *         instead of @f$X@f$ and @f$B@f$.
 *  @param x Right-hand side matrix @f$X@f$, gets overwritten by @f$B@f$. */
HEADER_PREFIX void
triangulareval_amatrix_amatrix(bool alower, bool atrans, bool aunit,
			       pcamatrix a, bool xtrans, pamatrix x);

/** @brief Add the product of two triangular matrices @f$A@f$ and
 *         @f$B@f$ to a matrix @f$C@f$, @f$C \gets C + \alpha A B@f$.
 *
 *  @param alpha Scaling factor @f$\alpha@f$.
 *  @param alower Set if @f$A@f$ is lower triangular, otherwise
 *         it is assumed to be upper triangular.
 *  @param atrans Set if @f$A^*@f$ is to be used instead of @f$A@f$.
 *  @param a Left triangular matrix @f$A@f$.
 *  @param blower Set if @f$B@f$ is lower triangular, otherwise
 *         if is assumed to be upper triangular.
 *  @param btrans Set if @f$B^*@f$ is to be used instead of @f$B@f$.
 *  @param b Right triangular matrix @f$B@f$.
 *  @param c Target matrix @f$C@f$. */
HEADER_PREFIX void
triangularaddmul_amatrix_amatrix(field alpha,
				 bool alower, bool atrans, pcamatrix a,
				 bool blower, bool btrans, pcamatrix b,
				 pamatrix c);

/** @brief Copy the lower triangular part of a matrix.
 *
 *  @param a Source matrix.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param b Target matrix. */
HEADER_PREFIX void
copy_lower_amatrix(pcamatrix a, bool aunit, pamatrix b);

/** @brief Copy the upper triangular part of a matrix.
 *
 *  @param a Source matrix.
 *  @param aunit Set if @f$A@f$ has unit diagonal.
 *  @param b Target matrix. */
HEADER_PREFIX void
copy_upper_amatrix(pcamatrix a, bool aunit, pamatrix b);

/* ------------------------------------------------------------
   Triangular decompositions
   ------------------------------------------------------------ */

/** @brief Compute the LR decomposition @f$A=LR@f$ of a matrix.
 *
 *  @param a Original matrix @f$A@f$.
 *         Upper part gets overwritten by @f$R@f$,
 *         strictly lower part by @f$L@f$.
 *	   @f$L@f$ has unit diagonal.
 *
 *  @returns Zero if successful, number of first failed step otherwise. */
HEADER_PREFIX uint
lrdecomp_amatrix(pamatrix a);

/** @brief Solve the linear system @f$A x = b@f$ using
 *         a LR factorization.
 *
 *  @param a LR factorization of @f$A@f$,
 *         as provided by @ref lrdecomp_amatrix.
 *  @param x Right-hand side @f$b@f$, gets overwritten by @f$x@f$. */
HEADER_PREFIX void
lrsolve_amatrix_avector(pcamatrix a, pavector x);

/** @brief Compute the Cholesky decomposition @f$A=LL^*@f$ of a
 *         self-adjoint positiv definite matrix.
 *
 *  @param a Original matrix @f$A@f$.
 *         Lower part gets overwritten by @f$L@f$.
 *
 *  @returns Zero if successful, number of first failed step otherwise. */
HEADER_PREFIX uint
choldecomp_amatrix(pamatrix a);

/** @brief Solve the linear system @f$A x = b@f$ using
 *         a Cholesky factorization.
 *
 *  @param a Cholesky factorization of @f$A@f$
 *         as provided by @ref choldecomp_amatrix.
 *  @param x Right-hand side @f$b@f$, gets overwritten by @f$x@f$. */
HEADER_PREFIX void
cholsolve_amatrix_avector(pcamatrix a, pavector x);

/** @brief Compute the LDLT decomposition @f$A=LDL^*@f$ of a
 *         self-adjoint matrix.
 *
 *  @param a Original matrix @f$A@f$.
 *         Diagonal part gets overwritten by @f$D@f$,
 *         strictly lower part by @f$L@f$.
 *         @f$L@f$ has unit diagonal.
 *
 *  @returns Zero if successful, number of first failed step otherwise. */
HEADER_PREFIX uint
ldltdecomp_amatrix(pamatrix a);

/** @brief Solve the linear system @f$A x = b@f$ using
 *         a LDLT factorization.
 *
 *  @param a LDLT factorization of @f$A@f$
 *         as provided by @ref ldltdecomp_amatrix.
 *  @param x Right-hand side @f$b@f$, gets overwritten by @f$x@f$. */
HEADER_PREFIX void
ldltsolve_amatrix_avector(pcamatrix a, pavector x);

/* ------------------------------------------------------------
   Orthogonal decompositions
   ------------------------------------------------------------ */

/** @brief Compute the QR decomposition @f$A=QR@f$ of a matrix.
 *
 *  @param a Original matrix @f$A@f$.
 *         Upper triangular part gets overwritten by @f$R@f$,
 *         strictly lower triangular part by Householder vectors.
 *  @param tau Scaling factors of Householder reflections . */
HEADER_PREFIX void
qrdecomp_amatrix(pamatrix a, pavector tau);

/** @brief Evaluate @f$b=Qx@f$ and variants for the matrix @f$Q@f$ of
 *         a QR decomposition.
 *
 *  @param qtrans Set if @f$Q^*@f$ is to be used instead of @f$Q@f$.
 *  @param a Householder vectors as provided by @ref qrdecomp_amatrix.
 *  @param tau Scaling factors as provided by @ref qrdecomp_amatrix.
 *  @param x Right-hand side vector @f$x@f$,
 *         gets overwritten by @f$b@f$. */
HEADER_PREFIX void
qrsubst_amatrix_avector(bool qtrans, pcamatrix a, pcavector tau, pavector x);

/** @brief Evaluate @f$B=QX@f$ and variants for the matrix @f$Q@f$ of
 *         a QR decomposition.
 *
 *  @param qtrans Set if @f$Q^*@f$ is to be used instead of @f$Q@f$.
 *  @param a Householder vectors as provided by @ref qrdecomp_amatrix.
 *  @param tau Scaling factors as provided by @ref qrdecomp_amatrix.
 *  @param x Right-hand side matrix @f$X@f$,
 *         gets overwritten by @f$B@f$. */
HEADER_PREFIX void
qrsubst_amatrix_amatrix(bool qtrans, pcamatrix a, pcavector tau,
			pamatrix x);

/** @brief Solve the linear system @f$A x = b@f$ using a
 *         QR factorization.
 *  @param a QR factorization of @f$A@f$ as provided by
 *         @ref qrdecomp_amatrix.
 *  @param tau Scaling factors as provided by @ref qrdecomp_amatrix.
 *  @param x Right-hand side vector @f$b@f$,
 *         gets overwritten by @f$x@f$. */
HEADER_PREFIX void
qrsolve_amatrix_avector(pcamatrix a, pcavector tau, pavector x);

/** @brief Compute the inverse @f$A^{-1}@f$ of a matrix by QR decomposition.
 *
 *  @param a Matrix @f$A@f$, gets overwritten by @f$A^{-1}@f$. */
HEADER_PREFIX void
qrinvert_amatrix(pamatrix a);

/** @brief Compute the factor @f$Q@f$ of a QR factorization.
 *
 *  @param a Householder vectors as provided by @ref qrdecomp_amatrix.
 *  @param tau Scaling factors as provided by @ref qrdecomp_amatrix.
 *  @param q Matrix, gets overwritten by @f$Q@f$. */
HEADER_PREFIX void
qrexpand_amatrix(pcamatrix a, pcavector tau, pamatrix q);

/** @} */

#endif
