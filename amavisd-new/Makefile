# $NetBSD: Makefile,v 1.13 2004/05/08 16:58:12 jcd Exp $

DISTNAME=	amavisd-new-${VERSION}-${PATCHLEVEL}
PKGNAME=	amavisd-new-${VERSION}${PATCHLEVEL}
CATEGORIES=	security mail
MASTER_SITES=	http://www.ijs.si/software/amavisd/ \
		http://mirrors.catpipe.net/amavisd-new/ \
		http://ftp.cfu.net/pub/amavisd-new/ \
		ftp://ftp.cfu.net/pub/amavisd-new/

MAINTAINER=	jdunn@aquezada.com
HOMEPAGE=	http://www.ijs.si/software/amavisd/
COMMENT=	Performance-enhanced daemonized version of amavis-perl

DEPENDS+=	spamassassin-[0-9]*:../../mail/spamassassin
DEPENDS+=	p5-Archive-Tar-[0-9]*:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Convert-TNEF-[0-9]*:../../converters/p5-Convert-TNEF
DEPENDS+=	p5-Convert-UUlib-[0-9]*:../../converters/p5-Convert-UUlib
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-MIME-tools>=5.313:../../mail/p5-MIME-tools
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Unix-Syslog-[0-9]*:../../sysutils/p5-Unix-Syslog

WRKSRC=         ${WRKDIR}/amavisd-new-${VERSION}

CONFLICTS+=     amavis-[0-9]*
CONFLICTS+=     amavis-perl-[0-9]*

USE_PERL5=	yes
PERL5_REQD=     5.8

.include "../../mk/bsd.prefs.mk"
USE_BUILDLINK3= yes

VERSION=	20030616
PATCHLEVEL=	p9

USE_PKGINSTALL=	YES
AMAVISUSER?=    vscan
AMAVISGROUP?=   vscan
AMAVISDIR?=     /var/amavis
AMAVISQUARANTINE?=      /var/virusmails

PKG_GROUPS=	${AMAVISGROUP}
PKG_USERS=	${AMAVISUSER}:${AMAVISGROUP}::Virus\\ Scanning\\ Account:${AMAVISDIR}:${SH}
RCD_SCRIPTS=	amavisd
CONF_FILES=	${PREFIX}/share/doc/amavisd-new/amavisd.conf ${PKG_SYSCONFDIR}/amavisd.conf

MESSAGE_SUBST+= AMAVISDIR=${AMAVISDIR}

BUILD_DEFS+=	AMAVISUSER
BUILD_DEFS+=	AMAVISGROUP
BUILD_DEFS+=	AMAVISDIR
BUILD_DEFS+=	AMAVISQUARANTINE
BUILD_DEFS+=	USE_MILTER

FILES_SUBST+=	AMAVISUSER=${AMAVISUSER}
FILES_SUBST+=	AMAVISGROUP=${AMAVISGROUP}
FILES_SUBST+=	AMAVISDIR=${AMAVISDIR}
FILES_SUBST+=	AMAVISQUARANTINE=${AMAVISQUARANTINE}

REPLACE_PERL+=	${WRKSRC}/amavisd

SUBST_CLASSES+=	amavisd
SUBST_STAGE.amavisd=	pre-build
SUBST_FILES.amavisd=	${WRKSRC}/amavisd	${WRKSRC}/amavisd.conf
SUBST_SED.amavisd=	-e "s|/etc/amavisd.conf|${PKG_SYSCONFDIR}/amavisd.conf|"	\
			-e "s|%%AMAVISDIR%%|${AMAVISDIR}|g"				\
			-e "s|%%AMAVISUSER%%|${AMAVISUSER}|g"				\
			-e "s|%%AMAVISGROUP%%|${AMAVISGROUP}|g"				\
			-e "s|%%AMAVISQUARANTINE%%|${AMAVISQUARANTINE}|g"		\
			-e "s|%%LOCALBASE%%|${LOCALBASE}|g"

PLIST_SUBST+=	AMAVIS_MILTER_USED=${AMAVIS_MILTER_USED}

.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--with-milterinc=${PREFIX}/include
CONFIGURE_ARGS+=--with-milterlib=${PREFIX}/lib
CONFIGURE_ARGS+=--with-runtime-dir=${AMAVISDIR}
CONFIGURE_ARGS+=--with-sockname=${AMAVISDIR}/amavisd.sock
CONFIGURE_ARGS+=--with-user=${AMAVISUSER}
CONFIGURE_DIRS=       ${WRKSRC}/helper-progs
BUILD_DIRS=   ${WRKSRC}/helper-progs
AMAVIS_MILTER_USED=

# Doesn't work with pth
PTHREAD_OPTS+=          require native

.else
do-configure:

do-build:
	@${ECHO} libmilter not used, not building amavis-milter and amavis

AMAVIS_MILTER_USED=	"@comment "
.endif

OWN_DIRS_PERMS=	${AMAVISDIR} ${AMAVISUSER} ${AMAVISGROUP} 0750 \
		${AMAVISQUARANTINE} ${AMAVISUSER} ${AMAVISGROUP} 0750

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd ${PREFIX}/sbin/amavisd
.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis-milter ${PREFIX}/sbin
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/AAAREADME.first ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/LDAP.schema ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/MANIFEST ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.chroot ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.contributed ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.customize ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.exim_v3 ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.exim_v4 ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.exim_v4_app ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.exim_v4_app2 ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.lookups ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.milter ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.old.scanners ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.performance ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.postfix ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.sendmail ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/README_FILES/README.sendmail-dual ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/amavisd-new
	${INSTALL_DATA} ${WRKSRC}/amavisd.conf ${PREFIX}/share/doc/amavisd-new/amavisd.conf

.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
