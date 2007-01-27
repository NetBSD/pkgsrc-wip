# $NetBSD: Makefile,v 1.1.1.1 2007/01/27 18:43:04 shattered Exp $
#

DISTNAME=		dvdisaster-0.70.4
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdisaster/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://dvdisaster.sourceforge.net/
COMMENT=		Protect data on unstable media using ECC

BUILD_DEPENDS+=		gettext-tools>=0.14:../../devel/gettext-tools

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIG_SHELL=		${PREFIX}/bin/bash
USE_TOOLS+=		bash gmake
MAKE_FILE=		GNUmakefile

pre-configure:
	cp ${FILESDIR}/scsi-netbsd.c ${WRKSRC}/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
