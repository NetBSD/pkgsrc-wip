# $NetBSD: Makefile,v 1.2 2008/04/04 10:42:59 rhialto Exp $

DISTNAME=		qvamps-0.98
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

DEPENDS+=		vamps-[0-9]*:../../wip/vamps
DEPENDS+=		dvdauthor-[0-9]*:../../multimedia/dvdauthor
DEPENDS+=		p5-qt3-[0-9]*:../../wip/p5-qt3

REPLACE_PERL+=		qvamps

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
