# $NetBSD: Makefile,v 1.1.1.1 2004/03/14 20:25:53 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/03/14 20:25:53 mpasternak Exp $
#

DISTNAME=		slackware_ncurses-5.4
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}
DISTFILES=		ncurses-5.4-i486-2.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://slackware.com/
COMMENT=		ncurses library for Slackware development

SLACK_GROUP=		l

post-extract:
	# remove libs already provided by slackware_aaa_elflibs
	cd ${WRKSRC} && ${RM} -rf lib
	cd ${WRKSRC} && ${RM} -rf usr/lib/*.so.*

.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
