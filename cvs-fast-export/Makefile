# $NetBSD: Makefile,v 1.1 2015/01/14 17:37:03 thomasklausner Exp $

DISTNAME=	cvs-fast-export-1.29
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

REPLACE_PYTHON+=	cvssync
USE_TOOLS+=	gmake # for srcdir
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PKGMANDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
