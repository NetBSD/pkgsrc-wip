# $NetBSD: Makefile,v 1.24 2025/03/02 18:24:57 leot Exp $

DISTNAME=	interactsh-1.2.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/interactsh
COMMENT=	OOB interaction gathering server and client library
LICENSE=	mit

.include "go-modules.mk"

# Do not install programs built only for testing
post-install:
.for _p_ in duration-testing examples load-testing
	${RM} ${DESTDIR}${PREFIX}/bin/${_p_}
.endfor

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
