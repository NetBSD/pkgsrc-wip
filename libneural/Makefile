# $NetBSD: Makefile,v 1.3 2005/11/28 00:27:25 rillig Exp $

DISTNAME= libneural-1.0.3
CATEGORIES=	devel
MASTER_SITES= http://ieee.uow.edu.au/~daniel/software/libneural/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE= http://ieee.uow.edu.au/~daniel/software/libneural/
COMMENT=	C++ library for creating 3-layer backpropagation neural networks

CONFIGURE_PREFIX+= ${PREFIX}
MAKE_FLAGS+= prefix=${PREFIX:Q}

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

post-install:
	${MKDIR}  ${PREFIX}/share/${DISTNAME}
	${CP} ${WRKSRC}/README ${PREFIX}/share/${DISTNAME}/README
	${CP} -r ${WRKSRC}/examples ${PREFIX}/share/${DISTNAME}/examples

.include "../../mk/bsd.pkg.mk"
