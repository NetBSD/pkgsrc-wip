# $NetBSD$

INETDXTRA_VERSION=	20140904
DISTNAME=		inetdxtra-${INETDXTRA_VERSION}_src
PKGNAME=		${DISTNAME:S/_src//}
CATEGORIES=		net
MASTER_SITES=		http://rawsontetley.org/oss/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://rawsontetley.org/proj_inetdxtra.html
COMMENT=		Collection of inetd based servers

LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gunzip

WRKSRC=			${WRKDIR}/inetdxtra

CFLAGS+=		-DSYSCONFDIR=\"${PKG_SYSCONFDIR}\"
CFLAGS+=		-DONELOG -DNORELATIVE -DCGI -DUPDATEPS

PKG_SYSCONFSUBDIR=	inetdxtra

LIBEXECDIR=		libexec/inetdxtra
DOCDIR=			share/doc/inetdxtra
EGDIR=			share/examples/inetdxtra

CONF_FILES=		${EGDIR}/inetd.conf.sample \
				${PKG_SYSCONFDIR}/inetd.conf
CONF_FILES+=		${EGDIR}/in.dhcp.conf.sample \
				${PKG_SYSCONFDIR}/in.dhcp.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${LIBEXECDIR} ${DOCDIR} ${EGDIR}

MAN1_PAGES=		in.jabberd/man/in.jabberd.1
MAN1_PAGES+=		in.www/man/in.www.1

do-install:
.for pp in ctcs dhcp dns jabberd mvp proxy smtp www
	${INSTALL_PROGRAM} ${WRKSRC}/in.${pp}/in.${pp} \
		${DESTDIR}${PREFIX}/${LIBEXECDIR}
	${INSTALL_DATA} ${WRKSRC}/in.${pp}/README \
		${DESTDIR}${PREFIX}/${DOCDIR}/README.${pp}
.endfor
.for mp in ${MAN1_PAGES}
	gunzip ${WRKSRC}/${mp}.gz
	${INSTALL_DATA} ${WRKSRC}/${mp} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mm}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/inetd.conf.sample \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/in.dhcp/in.dhcp.conf.sample \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
