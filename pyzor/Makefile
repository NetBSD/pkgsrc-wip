# $NetBSD: Makefile,v 1.3 2004/02/25 00:37:05 tomhensel Exp $

DISTNAME=	pyzor-0.4.0
PKGREVISION=    # empty
CATEGORIES=	mail
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=pyzor/)
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://pyzor.sourceforge.net/
COMMENT=	Collaborative, networked system to detect and block spam

.if defined(PYZOR_USE_PYZORD) && !empty(PYZOR_USE_PYZORD:M[Yy][Ee][Ss])
DEPENDS+=	${PYPKGPREFIX}-gdbm>=0nb1:../../databases/py-gdbm
# pyzords needs python with threading support
PYTHON_VERSIONS_ACCEPTED=	23pth
.else
PYTHON_VERSIONS_ACCEPTED=	23 23pth
.endif

BUILD_DEFS+=	PYZOR_USE_PYZORD

PYDISTUTILSPKG=	YES

PYTHON_PATCH_SCRIPTS=		scripts/pyzor	\
				scripts/pyzord

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
