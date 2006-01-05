# $NetBSD: Makefile,v 1.11 2006/01/05 10:11:26 ghen Exp $

DISTNAME=       superkaramba-0.33
CATEGORIES=     x11 misc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=netdragon/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://netdragon.sourceforge.net/
COMMENT=        Interactive eyecandy for your KDE desktop

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-pythondir=${PREFIX:Q}
USE_LIBTOOL=	yes

PYTHON_VERSIONS_ACCEPTED=	23

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full

.include "../../mk/bsd.pkg.mk"
