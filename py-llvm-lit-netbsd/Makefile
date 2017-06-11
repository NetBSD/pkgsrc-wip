# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

.include "../../wip/llvm-netbsd/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-llvm-lit-${LLVM_VERSION}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/docs/CommandGuide/lit.html
COMMENT=	LLVM Integrated Tester
LICENSE=	modified-bsd

PYSETUPSUBDIR=	utils/lit

INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/lit/lit.py \
		${DESTDIR}${PREFIX}/bin/llvm-lit-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
