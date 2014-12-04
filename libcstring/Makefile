# $NetBSD: Makefile,v 1.1 2014/12/04 23:03:14 othyro Exp $

DISTNAME=	20141018
PKGNAME=	libcstring-${DISTNAME}
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/libyal/libcstring/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libcstring/
COMMENT=	Library for cross-platform C string functions
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	aclocal autoconf autoheader automake autopoint msgfmt msgmerge
USE_TOOLS+=	pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcstring.pc.in

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	autogen.sh
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/bin|${PREFIX}/bin|1"
SUBST_STAGE.prefix=	post-patch

.include "options.mk"

pre-configure:
	set -e; cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ./autogen.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
