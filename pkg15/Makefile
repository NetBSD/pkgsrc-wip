# $NetBSD: Makefile,v 1.8 2015/06/26 12:56:33 khorben Exp $
#

VERSION=	1.5.4
DISTNAME=	${VERSION}
PKGNAME=	pkg15-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	https://github.com/freebsd/pkg/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/freebsd/pkg/archive/
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/pkg-${VERSION}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CPPFLAGS+=	-D_LOCALBASE="\"${PREFIX}\""
CPPFLAGS+=	-DPORTSDIR="\"/usr/pkgsrc\""

AUTO_MKDIRS=	yes

EGDIR=		${PREFIX}/share/examples/pkg

CONF_FILES=	${EGDIR}/pkg.conf.sample \
		${PKG_SYSCONFDIR}/pkg.conf

SUBST_CLASSES+=	manpages-prefix
SUBST_STAGE.manpages-prefix=	pre-install
SUBST_FILES.manpages-prefix=	docs/pkg-install.8 docs/pkg-repo.8
SUBST_FILES.manpages-prefix+=	docs/pkg-search.8 docs/pkg-update.8
SUBST_FILES.manpages-prefix+=	docs/pkg-upgrade.8 docs/pkg.8
SUBST_FILES.manpages-prefix+=	docs/pkg.conf.5
SUBST_SED.manpages-prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.manpages-prefix=	Correct the installation prefix in manual pages.

SUBST_CLASSES+=	pkgconf-prefix
SUBST_STAGE.pkgconf-prefix=	pre-install
SUBST_FILES.pkgconf-prefix=	src/pkg.conf.sample
SUBST_SED.pkgconf-prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.pkgconf-prefix=	Correct the installation prefix in pkg.conf(5).

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/pkg.conf.sample \
		${DESTDIR}${EGDIR}/pkg.conf.sample

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
