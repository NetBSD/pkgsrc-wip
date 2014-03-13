# $NetBSD: Makefile,v 1.3 2014/03/13 20:08:47 fhajny Exp $
#

DISTNAME=	whisper-0.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	-https://github.com/graphite-project/whisper/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://launchpad.net/graphite
COMMENT=	Fixed-size database, similar in design to RRD
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
