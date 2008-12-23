# $NetBSD: Makefile,v 1.2 2008/12/23 13:06:12 pebog Exp $

DISTNAME=		dcc-1.3.99
#PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://www.rhyolite.com/dcc/source/old/
EXTRACT_SUFX=		.tar.Z

OWNER=			petar@smokva.net
HOMEPAGE=		http://www.rhyolite.com/dcc/
COMMENT=		Anti-spam content filter

LICENSE=		dcc-free-license
LICENSE_FILE=		${FILESDIR}/dcc-free-license
PKG_DESTDIR_SUPPORT=	destdir

DCC_USER?=		dcc
DCC_GROUP?=		dcc
DCC_HOME?=		${VARBASE}/dcc
DCC_RUN?=		${VARBASE}/run/dcc
#
#	expanded in INSTALL
#
FILES_SUBST+=		DCC_USER=${DCC_USER} \
			DCC_GROUP=${DCC_GROUP} \
			DCC_HOME=${DCC_HOME} \
			DCC_EGDIR=${DCC_EGDIR}
#
#	expanded in files/dcc{d,ifd,m}
#
FILES_SUBST+=		DCC_RUN=${DCC_RUN}

SUBST_CLASSES+=		egd
SUBST_STAGE.egd=	post-patch
SUBST_FILES.egd=	homedir/Makefile.in \
			cgi-bin/Makefile.in
SUBST_SED.egd=		-e 's!$$(DCC_HOMEDIR)!${DCC_EGDIR}!g' \
			-e 's!@cgibin@!${DCC_EGDIR}/cgi-bin!g'
SUBST_MESSAGE.egd=	Adjusting home/cgi installation paths

SUBST_CLASSES+=		dae
SUBST_STAGE.dae=	post-patch
SUBST_FILES.dae=	homedir/dcc_conf.in
SUBST_SED.dae=		-Ee 's!^(DCC(D|IFD|M)_ENABLE=)off$$!\1on!'
SUBST_MESSAGE.dae=	Enabling all daemons in dcc_conf

HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

CONFIGURE_ENV+=		PERL=${PERL5} \
			DCC_XARGS=${XARGS}

CONFIGURE_ARGS=		--homedir=${DCC_HOME} \
			--bindir=${PREFIX}/bin \
			--libexecdir=${PREFIX}/libexec \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--with-uid=${DCC_USER} \
			--with-rundir=${DCC_RUN}

.include "options.mk"

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/cat8 \
			share/examples/dcc/cgi-bin

PKG_GROUPS=		${DCC_GROUP}
PKG_USERS=		${DCC_USER}:${DCC_GROUP}

OWN_DIRS_PERMS=		${DCC_HOME} ${DCC_USER} ${DCC_GROUP} 0755 \
			${DCC_HOME}/log ${DCC_USER} ${DCC_GROUP} 0710

DCC_EGDIR=		${PREFIX}/share/examples/dcc
#
#	see options.mk for more CONF_FILES
#
CONF_FILES+=		${DCC_EGDIR}/dcc_conf ${DCC_HOME}/dcc_conf \
			${DCC_EGDIR}/whiteclnt ${DCC_HOME}/whiteclnt \
			${DCC_EGDIR}/whitecommon ${DCC_HOME}/whitecommon

INSTALL_DCC_EGDIR=	${INSTALL} -m 644 -o ${DCC_USER} -g ${ROOT_GROUP}

post-install:
	${INSTALL_DCC_EGDIR} ${WRKSRC}/homedir/ids ${DESTDIR}${DCC_EGDIR}; \
	${INSTALL_DCC_EGDIR} ${WRKSRC}/homedir/map.txt ${DESTDIR}${DCC_EGDIR};

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
