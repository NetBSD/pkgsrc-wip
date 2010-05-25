# $NetBSD: Makefile,v 1.3 2010/05/25 04:55:31 emil_s Exp $
#

DISTNAME=	s3cmd-0.9.9.91
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s3cmd/}

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://s3tools.org/s3cmd/
COMMENT=	Tool for copying files to/from Amazon S3
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,"share/man","${PKGMANDIR}",g'

PYDISTUTILSPKG=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
