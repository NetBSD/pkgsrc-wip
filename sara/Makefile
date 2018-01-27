# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:30 othyro Exp $
#

DISTNAME=		sara-7.4.4
CATEGORIES=		security
MASTER_SITES=		http://www-arc.com/sara/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-arc.com/sara/
COMMENT=		Security Auditor's Research Assistant

DEPENDS+=		nmap>=3.50:../../net/nmap
DEPENDS+=		fping>=2.4:../../net/fping
DEPENDS+=		samba>=3.0:../../net/samba

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run pax

EGDIR=		${PREFIX}/share/examples/sara
EGFILES=	htm.cf paths.pl paths.sh ports programs sara.cf \
		services version.pl xml.cf

.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

SUBST_CLASSES+=		grp
SUBST_STAGE.grp=	post-patch
SUBST_FILES.grp=	src/misc/rex.c src/nfs-chk/nfs-chk.c
SUBST_SED.grp=		-e 's,GETGROUPS_T,gid_t,g'

# Disable build of fping.
SUBST_CLASSES+=		fping
SUBST_STAGE.fping=	post-patch
SUBST_FILES.fping=	src/fping/Makefile
SUBST_SED.fping=	-e 's,: $$(PROG),:,g'

# Change default path
SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-install
SUBST_FILES.path=	sara perl/* perllib/* bin/* html/*.pl
SUBST_SED.path =	-e 's,config\/,${EGDIR}/,g'
SUBST_SED.path+=	-e 's,perl.*\/,${PREFIX}/share/sara/,g'
SUBST_SED.path+=	-e 's,rules/,${PREFIX}/share/sara/rules/,g'
SUBST_SED.path+=	-e 's,`pwd`,\"${PREFIX}/share/sara/\",g'

# Default bin path
SUBST_CLASSES+=		defpath
SUBST_STAGE.defpath=	post-build
SUBST_FILES.defpath=	config/paths.pl
SUBST_SED.defpath =	-e 's,\"bin/,\"${PREFIX}/bin/,g'
SUBST_SED.defpath+=	-e 's,config,${EGDIR}/,g'

REPLACE_PERL=	bin/get_targets bin/faux_fping sara add_user \
	bin/*.sara* bin/*.sara.ext perl/*.pl perl/contrib/* html/*.pl \
	html/docs/*.pl plugins/*.pi bin/fwping

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sara ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/docs/sara.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/config/* ${DESTDIR}${EGDIR}/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sara/
	${INSTALL_DATA} ${WRKSRC}/perl/*.pl ${DESTDIR}${PREFIX}/share/sara/
	${INSTALL_DATA} ${WRKSRC}/perllib/getopts.pl ${DESTDIR}${PREFIX}/share/sara/
	${INSTALL_DATA} ${WRKSRC}/perllib/ctime.pl ${DESTDIR}${PREFIX}/share/sara/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sara ${DESTDIR}${PREFIX}/bin/
.for bin in faux_fping fwping get_targets
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${bin} ${DESTDIR}${PREFIX}/bin/
.endfor
.for bin in ddos-scan dscan ftp_scan sys_socket sqlanlz yp-chk \
	nfs-chk irix-telnet rcmd rex safe_finger tcp_scan timeout udp_scan
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${bin} ${DESTDIR}${PREFIX}/bin/
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sara/rules/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sara/html/
	cd ${WRKSRC}/rules && pax -rwppm . ${DESTDIR}${PREFIX}/share/sara/rules/
	cd ${WRKSRC}/html && pax -rwppm . ${DESTDIR}${PREFIX}/share/sara/html/

.include "../../mk/bsd.pkg.mk"
