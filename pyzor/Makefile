# $NetBSD: Makefile,v 1.5 2005/11/03 14:45:09 rillig Exp $

DISTNAME=	pyzor-0.4.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyzor/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://pyzor.sourceforge.net/
COMMENT=	Collaborative, networked system to detect and block spam

.if defined(PYZOR_USE_PYZORD) && !empty(PYZOR_USE_PYZORD:M[Yy][Ee][Ss])
DEPENDS+=	${PYPKGPREFIX}-gdbm>=0nb1:../../databases/py-gdbm
.endif

PYTHON_VERSIONS_ACCEPTED=	23

BUILD_DEFS+=	PYZOR_USE_PYZORD

PYDISTUTILSPKG=	YES

PYTHON_PATCH_SCRIPTS=		scripts/pyzor	\
				scripts/pyzord

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
