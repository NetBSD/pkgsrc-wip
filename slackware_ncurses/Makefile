# $NetBSD: Makefile,v 1.3 2005/07/27 16:30:39 thomasklausner Exp $
# $Id: Makefile,v 1.3 2005/07/27 16:30:39 thomasklausner Exp $
#

DISTNAME=		ncurses-5.4-i486-2
PKGNAME=		slackware_ncurses-5.4
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://slackware.com/
COMMENT=		ncurses library for Slackware development

SLACK_GROUP=		l

post-extract:
	# remove libs already provided by slackware_aaa_elflibs
	cd ${WRKSRC} && ${RM} -rf lib
	cd ${WRKSRC} && ${RM} -rf usr/lib/*.so.*

.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
