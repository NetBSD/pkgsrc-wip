# $NetBSD: Makefile,v 1.2 2004/01/28 17:12:37 rasputnik Exp $

DISTNAME= libneural-1.0.3
CATEGORIES=	devel
MASTER_SITES= http://ieee.uow.edu.au/~daniel/software/libneural/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE= http://ieee.uow.edu.au/~daniel/software/libneural/
COMMENT=	C++ library for creating 3-layer backpropagation neural networks

CONFIGURE_PREFIX+= ${PREFIX}
MAKE_FLAGS+= prefix=${PREFIX}

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

post-install:
	${MKDIR}  ${PREFIX}/share/${DISTNAME}
	${CP} ${WRKSRC}/README ${PREFIX}/share/${DISTNAME}/README
	${CP} -r ${WRKSRC}/examples ${PREFIX}/share/${DISTNAME}/examples

.include "../../mk/bsd.pkg.mk"
