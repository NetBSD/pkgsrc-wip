# $NetBSD: Makefile,v 1.7 2012/02/06 22:56:35 fhajny Exp $

DISTNAME=	pyzor-0.5.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyzor/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://sourceforge.net/apps/trac/pyzor/
COMMENT=	Collaborative, networked system to detect and block spam
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
