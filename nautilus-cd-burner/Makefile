# $NetBSD: Makefile,v 1.1.1.1 2003/10/27 00:51:19 xtraeme Exp $
#

DISTNAME=	nautilus-cd-burner-0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-cd-burner/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CD burner view for Nautilus

DEPENDS+=		cdrecord-[0-9]*:../../sysutils/cdrecord
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0/modules

EGDIR=			${PREFIX}/share/examples/nautilus-cd-burner
CONF_FILES=		${EGDIR}/mapping-modules.conf \
			${PKG_SYSCONFDIR}/mapping-modules.conf

.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
