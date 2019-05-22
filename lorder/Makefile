# $NetBSD: Makefile,v 1.5 2012/10/03 09:00:45 asau Exp $
#

# XXX This version is the CVS revision number from NetBSD's
# usr.bin/lorder/lorder.sh. It also was known as 8.1 back in 1993.
DISTNAME=	lorder-1.12
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE=
COMMENT=	Determine interdependencies in a list of object files

NO_CONFIGURE=	YES
NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

# XXX This would be a good place to use PREFER_PKGSRC
.if empty(OPSYS:M*BSD)
DEPENDS+=	mktemp>=1.4:../../sysutils/mktemp
MKTEMP=		${PREFIX}/bin/mktemp
.else
MKTEMP=		mktemp
.endif

# This also uses nm(1) which could be from binutils package.
# Maybe a DEPENDS for it too?  Then again, nobody would use lorder
# unless they had binutils, I assume.

post-patch:
	${SED} -e "s:MKTEMP=mktemp:MKTEMP=${MKTEMP}:" \
		< ${FILESDIR}/lorder.sh > ${WRKDIR}/lorder

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/lorder ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/lorder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
