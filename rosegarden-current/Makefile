# $NetBSD: Makefile,v 1.8 2006/01/05 10:11:26 ghen Exp $
#

DISTNAME=	rosegarden-4-0.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rosegarden/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	Development release of rosegarden

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-qt-dir=/usr/X11R6/qt3

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
