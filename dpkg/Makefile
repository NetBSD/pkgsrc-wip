# $NetBSD: Makefile,v 1.3 2003/09/27 22:28:20 jeremy-c-reed Exp $
#

DISTNAME=	dpkg_1.9.21
PKGNAME=	dpkg-1.9.21
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dpkg/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://packages.debian.org/stable/base/dpkg.html
COMMENT=	Package maintenance system for Debian

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PERL5=		build
USE_NCURSES=		yes # Needed for dselect
USE_PKGINSTALL=		yes

REPLACE_PERL=		${WRKSRC}/scripts/*.pl

DPKGDIR=		${DPKG_DB_PATH}
OWN_DIRS=		${DPKGDIR}

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-start-stop-daemon=no
CONFIGURE_ARGS+=	--with-sgml-doc=no
CONFIGURE_ARGS+=	--with-admindir=${DPKGDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/dpkg

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
