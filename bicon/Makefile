# $NetBSD: Makefile,v 1.1 2015/03/05 16:37:14 mbowie Exp $
#

PKGNAME=	bicon-0.4
DISTNAME=	master
CATEGORIES=	shells
MASTER_SITES=	https://github.com/behdad/bicon/archive/
FETCH_USING=	curl
EXTRACT_SUFX=	.zip

MAINTAINER=	mbowie@rocketspace.com
HOMEPAGE=	https://github.com/behdad/bicon/
COMMENT=	Bidirection text console
LICENSE=	python-software-foundation

# Cannot use until GIT_TAG is supported
#GIT_REPOSITORIES=	bicon
#GIT_MODULE.bicon=	bicon
#GIT_REPO.bicon=	https://github.com/behdad/bicon.git
#GIT_TAG.bicon=		0.4
#PKGSRC_SETENV=		GIT_SSL_NO_VERIFY=true

WRKSRC=		${WRKDIR}/bicon-master

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf autoreconf automake gmake
USE_TOOLS+=	pkg-config perl bash:run

GNU_CONFIGURE=	yes

REPLACE_BASH+=	bin/bicon.in
REPLACE_PERL+=	font/bicon-bdf2psf.pl

pre-configure:
	cd ${WRKSRC} && autoreconf -i

# Cannot use until GIT_TAG is supported
#.include "../../wip/mk/git-package.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
