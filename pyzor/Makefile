# $NetBSD: Makefile,v 1.8 2012/10/07 13:57:33 asau Exp $

DISTNAME=	pyzor-0.5.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyzor/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://sourceforge.net/apps/trac/pyzor/
COMMENT=	Collaborative, networked system to detect and block spam
LICENSE=	gnu-gpl-v2

.if defined(PYZOR_USE_PYZORD) && !empty(PYZOR_USE_PYZORD:M[Yy][Ee][Ss])
DEPENDS+=	${PYPKGPREFIX}-gdbm>=0nb1:../../databases/py-gdbm
.endif

BUILD_DEFS+=	PYZOR_USE_PYZORD

PYDISTUTILSPKG=	YES

PYTHON_PATCH_SCRIPTS=		scripts/pyzor	\
				scripts/pyzord

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
