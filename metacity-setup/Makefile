# $NetBSD: Makefile,v 1.1.1.1 2003/05/23 12:31:03 marc Exp $
#

DISTNAME=		metacity-setup-0.7.1
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=metacity-setup/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://metacity-setup.sourceforge.net/
COMMENT=		Configuration editor for Metacity

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
