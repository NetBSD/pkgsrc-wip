# $NetBSD$

DISTNAME=	darkman-v2.0.1
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=WhyNotHugo/darkman/-/archive/v2.0.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://darkman.whynothugo.nl
COMMENT=	Daemon to control dark-mode and light-mode transitions
LICENSE=	0-clause-bsd

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
