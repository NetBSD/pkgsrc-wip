# $NetBSD: Makefile,v 1.2 2006/12/20 02:44:51 schnoebe Exp $
# FreeBSD Id: Makefile,v 1.9 2005/11/09 07:48:10 pav Exp

DISTNAME=	ejabberd-1.1.2
CATEGORIES=	chat
MASTER_SITES=	http://www.jabber.ru/files/ejabberd/ \
		http://www.process-one.net/en/projects/ejabberd/download/${PKGVERSION}/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://ejabberd.jabber.ru/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

CONFLICTS+=	jabberd2-[0-9]*
CONFLICTS+=	jabberd-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

# much prefer to be explicit about the configure settings
# rather than depending on the defaults to continue to be sane or same
# between versions
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-mod_irc
CONFIGURE_ARGS+=	--enable-mod_muc
CONFIGURE_ARGS+=	--enable-eldap
CONFIGURE_ARGS+=	--enable-web
CONFIGURE_ARGS+=	--enable-tls
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-ejabberd_zlib
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-erlang=${BUILDLINK_PREFIX.erlang}

CONFIGURE_DIRS+=	src
BUILD_DIRS+=	src
# WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ENV=	PKGVERSION=${PKGVERSION:Q}
PLIST_SUBST+=	DISTNAME=${DISTNAME:Q} PKGBASE=${PKGBASE:Q}

FILES_SUBST+=	DISTNAME=${DISTNAME:Q} PKGBASE=${PKGBASE:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
FILES_SUBST+=	EGDIR=${EGDIR:Q}

RCD_SCRIPTS=	ejabberd

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/ejabberd.inetrc ${PKG_SYSCONFDIR}/ejabberd.inetrc
CONF_FILES+=	${EGDIR}/ejabberd.cfg ${PKG_SYSCONFDIR}/ejabberd.cfg
CONF_FILES+=	${EGDIR}/ejabberd.defaults ${PKG_SYSCONFDIR}/ejabberd.defaults

post-install:
#	${INSTALL_SCRIPT} ${WRKDIR}/ejabberd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/ejabberdctl ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/ejabberd.defaults ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ejabberd.cfg.example ${EGDIR}/ejabberd.cfg
	${INSTALL_DATA} ${FILESDIR}/ejabberd.inetrc ${EGDIR}

#	${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
#	${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}

	${INSTALL_DATA_DIR} ${PREFIX}/shre/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/${DISTNAME}
	# don't really need the make file, do we?
	${RM} ${PREFIX}/share/doc/${DISTNAME}/Makefile

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Makefile.in
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@DISTNAME@,${DISTNAME},g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
