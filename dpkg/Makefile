# $NetBSD: Makefile,v 1.5 2003/12/28 08:35:05 xtraeme Exp $
#

DISTNAME=	dpkg_1.9.21
PKGNAME=	${DISTNAME:S/_/-/}
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
USE_NCURSES=		# tigetstr()
USE_PERL5=		build
USE_PKGINSTALL=		yes

REPLACE_PERL=		${WRKSRC}/scripts/*.pl

ADMIN_DIR=		${PREFIX}/var/db

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-start-stop-daemon=no
CONFIGURE_ARGS+=	--with-sgml-doc=no
CONFIGURE_ARGS+=	--with-admindir=${ADMIN_DIR}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/dpkg

#.include "../../wip/debian_base/linux.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
