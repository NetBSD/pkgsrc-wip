# $NetBSD: Makefile,v 1.1.1.1 2004/06/02 11:32:47 poppnk Exp $
#

DISTNAME=		sara-5.0.5b
CATEGORIES=		wip security
MASTER_SITES=		http://www-arc.com/sara/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www-arc.com/sara/
COMMENT=		Security Auditor's Research Assistant

DEPENDS+=		nmap>=3.50:../../net/nmap/
DEPENDS+=		fping>=2.4:../../net/fping/

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PERL5=			yes
#PKG_DEBUG_LEVEL=2

SUBST_CLASSES+=	grp
SUBST_STAGE.grp= post-patch
SUBST_FILES.grp= src/misc/rex.c src/nfs-chk/nfs-chk.c
SUBST_SED.grp= -e 's,GETGROUPS_T,gid_t,g'

# Disable build of fping.
SUBST_CLASSES+= fping
SUBST_STAGE.fping= post-patch
SUBST_FILES.fping= src/fping/Makefile
SUBST_SED.fping= -e 's,: $$(PROG),:,g'

# Change default path
SUBST_CLASSES+= path
SUBST_STAGE.path= pre-install
SUBST_FILES.path= sara perl/* perllib/* bin/* html/*.pl
SUBST_SED.path = -e 's,config\/,${PREFIX}/etc/sara/,g'
SUBST_SED.path+= -e 's,perl.*\/,${PREFIX}/share/sara/,g'
SUBST_SED.path+= -e 's,rules/,${PREFIX}/share/sara/rules/,g'
SUBST_SED.path+= -e 's,`pwd`,\"${PREFIX}/share/sara/\",g'

# Default bin path
SUBST_CLASSES+= defpath
SUBST_STAGE.defpath=post-build
SUBST_FILES.defpath=config/paths.pl
SUBST_SED.defpath = -e 's,\"bin/,\"${PREFIX}/bin/,g'
SUBST_SED.defpath+= -e 's,config,${PREFIX}/etc/sara/,g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sara ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/sara.8  ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/etc/sara/
	${INSTALL_DATA} ${WRKSRC}/config/* ${PREFIX}/etc/sara/
	${INSTALL_DATA_DIR} ${PREFIX}/share/sara/
	${INSTALL_DATA} ${WRKSRC}/perl/*.pl ${PREFIX}/share/sara/
	${INSTALL_DATA} ${WRKSRC}/perllib/getopts.pl ${PREFIX}/share/sara/
	${INSTALL_DATA} ${WRKSRC}/perllib/ctime.pl ${PREFIX}/share/sara/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sara ${PREFIX}/bin/
.for bin in faux_fping fwping get_targets
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${bin} ${PREFIX}/bin/
.endfor
.undef bin
.for bin in ddos-scan dscan ftp_scan sys_socket sqlanlz yp-chk \
	nfs-chk irix-telnet rcmd rex safe_finger tcp_scan timeout udp_scan
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${bin} ${PREFIX}/bin/
.endfor
.undef bin
	#${PAX} -rwppm ${WRKSRC}/rules/* ${PREFIX}/share/sara/rules/
	${INSTALL_DATA_DIR} ${PREFIX}/share/sara/rules/
	${CP} -rf ${WRKSRC}/rules/* ${PREFIX}/share/sara/rules/
	${INSTALL_DATA_DIR} ${PREFIX}/share/sara/html/
	${CP} -rf ${WRKSRC}/html/* ${PREFIX}/share/sara/html/

.include "../../mk/bsd.pkg.mk"
