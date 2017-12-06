# $NetBSD$

DISTNAME=	boinc-7.9.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BOINC/}

GIT_REPOSITORIES=	boinc
GIT_REPO.boinc=		https://github.com/BOINC/boinc.git
WRKSRC=			${WRKDIR}/boinc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://boinc.berkeley.edu/
COMMENT=	Open-source software for volunteer computing
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf	# for autoreconf
USE_TOOLS+=	automake pkg-config
USE_TOOLS+=	gmake	# seems to be required only by ${WRKSRC}/_autosetup

USE_LANGUAGES=	c c++ fortran

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-manager

pre-configure:
	${RUN} cd ${WRKSRC} && ./_autosetup

.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
