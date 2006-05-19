# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:37 ykomatsu Exp $
# $Id: Makefile,v 1.5 2006/05/19 16:51:37 ykomatsu Exp $
#

DISTNAME=		glibc-2.3.2-i486-5
PKGNAME=		slackware_glibc-2.3.2
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://slackware.com/
COMMENT=		glibc with development files for Slackware

SLACK_GROUP=		l

.include "../../mk/bsd.prefs.mk"

pre-install:
	#
	# remove stuff, that's already in slackware_glibc_so to avoid
	# warnings from pkg_add
	#
	${RM} -rf ${WRKSRC}/lib
	${RM} -rf ${WRKSRC}/sbin

.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
