# $NetBSD: Makefile,v 1.3 2003/08/20 17:31:49 tvierling Exp $
#
# XXX WIP: only installs parts necessary for client operation.
# Server parts still in work (need to add informational texts into
# $PREFIX/share/examples/mixmaster that correspond with what the
# ugly interactive "Install" script does).

DISTNAME=		mixmaster-2.9.0
CATEGORIES=		wip security mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mixmaster/}

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://mixmaster.sourceforge.net/
COMMENT=		The Mixmaster anonymous remailer client

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes

BUILD_DEFS+=		USE_IDEA
BUILD_DIRS=		${WRKSRC}/Src
MAKE_FLAGS+=		CC=${CC} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q} LIBS=
MAKEFILE=		Makefile.in
PKG_SYSCONFSUBDIR=	mixmaster

# Configuration files modifiable at runtime.
egdir=			${PREFIX}/share/examples/mixmaster
CONF_FILES+=		${egdir}/mix.cfg ${PKG_SYSCONFDIR}/mix.cfg

# We don't install the time-sensitive remailer lists, however.
installed_confs=	abuse.txt.in adminkey.txt blocked.txt.in \
			dest.alw dest.blk end.hlp header.blk \
			intro.hlp mix.cfg mix.cfg.server \
			mix.hlp news.hlp pgp.hlp pgponly.hlp \
			rab.blk reply.txt.in type1.hlp usage.txt.in

.include "../../mk/bsd.prefs.mk"

.if defined(USE_IDEA) && ${USE_IDEA} == YES
.include "../../security/libidea/buildlink2.mk"
CFLAGS+=		-DUSE_IDEA
LDFLAGS+=		-lidea # must go before -lcrypto to override
.else
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.noIDEA
.endif

# note: HAVE_GETDOMAINNAME is *not* set.  Mixmaster abuses this value,
# using it as DNS (not NIS) domain name.

CFLAGS+=		-DUSE_NCURSES -DUSE_PCRE -DUSE_SOCK -DUSE_ZLIB \
			-DGLOBALMIXCONF=\"${PKG_SYSCONFDIR}/mix.cfg\"
LDFLAGS+=		-lcrypto -lncurses -lpcre -lz

post-extract:
	${MV} ${WRKSRC}/conf/mix.cfg.ex ${WRKSRC}/conf/mix.cfg.server

post-patch:
	${MKDIR} ${WRKSRC}/conf.eg
	@cd ${WRKSRC}/conf && for f in ${installed_confs}; do \
		${SED} ${FILES_SUBST_SED} <$$f >../conf.eg/$$f; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/mix ${PREFIX}/bin/mix
	${INSTALL_DATA} ${WRKSRC}/mix.1 ${PREFIX}/man/man1/mix.1
	${INSTALL_DATA_DIR} ${egdir}
	${INSTALL_DATA} ${WRKSRC}/conf.eg/* ${egdir}/

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
