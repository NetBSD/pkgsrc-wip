# $NetBSD: Makefile,v 1.1.1.1 2004/12/26 18:03:24 thomasklausner Exp $
#

DISTNAME=		lingoteach-lesson-0.4.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lingoteach/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lingoteach.sourceforge.net/
COMMENT=		Lesson files for lingoteach

DEPENDS+=		lingoteach-ui-[0-9]*:../../wip/lingoteach-ui

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
