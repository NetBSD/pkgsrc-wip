# $NetBSD: Makefile,v 1.5 2010/01/18 09:38:31 thomasklausner Exp $

DISTNAME=		qvamps-0.98
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vamps/}

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://vamps.sourceforge.net/
COMMENT=		GUI for shrinking DVDs (for vamps)

USE_TOOLS+=		gmake
USE_TOOLS+=		perl

ALL_ENV+=		LUPDATE=${BUILDLINK_PREFIX.qt3-tools}/qt3/bin/lupdate
ALL_ENV+=		LRELEASE=${BUILDLINK_PREFIX.qt3-tools}/qt3/bin/lrelease
ALL_ENV+=		LOADLIBES="-ldvdread -Wl,-R${BUILDLINK_PREFIX.libdvdread}/lib"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_MESSAGE.etc=	Patching configuration file directory
SUBST_SED.etc=		s=/usr/share/qvamps/etc=${PKG_SYSCONFDIR}/qvamps=
SUBST_FILES.etc=	QVamps.pm

MAKE_DIRS=		${PKG_SYSCONFDIR}/qvamps

DEPENDS+=		vamps-[0-9]*:../../wip/vamps
DEPENDS+=		dvdauthor-[0-9]*:../../multimedia/dvdauthor
DEPENDS+=		p5-qt3-[0-9]*:../../wip/p5-qt3

REPLACE_PERL+=		qvamps
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
