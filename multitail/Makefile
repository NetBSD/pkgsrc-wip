# $NetBSD: Makefile,v 1.24 2015/08/18 07:31:13 wiz Exp $
#

DISTNAME=	multitail-6.4.2
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_NCURSES=		yes	# Needs the <panel> library.
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/multitail	\
			share/examples/multitail

CONF_FILES=	${PREFIX:Q}/share/examples/multitail/multitail.conf	\
		${PKG_SYSCONFDIR:Q}/multitail.conf

SUBST_CLASSES+=	path
SUBST_MESSAGE.path=	Adjust DESTDIR and PREFIX
SUBST_FILES.path=	Makefile
SUBST_STAGE.path=	post-patch
SUBST_VARS.path=	DESTDIR PREFIX

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-lutil
LDFLAGS+=		-lsocket -lnsl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/multitail ${DESTDIR}${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/multitail.1 ${DESTDIR}${PREFIX:Q}/man/man1/
	${INSTALL_DATA} ${WRKSRC:Q}/multitail.conf \
		${DESTDIR}${PREFIX:Q}/share/examples/multitail/
	cd ${WRKSRC:Q} && ${INSTALL_DATA} *.txt manual*.html \
		${DESTDIR}${PREFIX:Q}/share/doc/multitail/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
