# $NetBSD$

DISTNAME=	arduino-ctags-${GITHUB_TAG:S/-arduino/./}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_PROJECT=	ctags
GITHUB_TAG=	5.8-arduino11
EXTRACT_SUFX=	.zip

MAINTAINER=	krz.lasocki@gmail.com
HOMEPAGE=	https://github.com/arduino/ctags
COMMENT=	Arduino ctags, based on Exuberant ctags
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+= bin man/man1
.include "../../mk/bsd.pkg.mk"
