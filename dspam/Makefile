# $NetBSD: Makefile,v 1.1.1.1 2004/03/13 16:11:15 tomhensel Exp $
# FreeBSD Id: ports/mail/dspam/Makefile,v 1.9 2004/01/31 22:51:09 sergei Exp

DISTNAME=	dspam-${_DSPAM_VER}
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://www.nuclearelephant.com/projects/dspam/
COMMENT=	Scalable statistical-algorithmic hybrid anti-spam filter

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

CONFIGURE_ARGS=	--with-userdir=${PREFIX}/etc/dspam

DOCS=		CHANGE README RELEASE.NOTES LICENSE

DOCSDIR=	${PREFIX}/share/doc/dspam
EXAMPLESDIR=	${PREFIX}/share/examples/dspam

PLIST_SUBST+=	DOCSDIR=${DOCSDIR:S/${PREFIX}\///} \
		EXAMPLESDIR=${EXAMPLESDIR:S/${PREFIX}\///}

MESSAGE_SUBST+=	DOCSDIR=${DOCSDIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

_DSPAM_VER=	2.8.3

BUILD_DEFS+=		USE_MYSQL \
			DSPAM_USE_MAILDROP DSPAM_USE_PROCMAIL DSPAM_USE_MAILLOCAL \
			DSPAM_CHI_SQUARE \
			DSPAM_USE_SGID \
			DSPAM_SPAM_DELIVERY \
			DSPAM_SOURCE_ADDRESS_TRACKING \
			DSPAM_SIGNATURE_ATTACHMENTS \
			DSPAM_HOMEDIR_DOTFILES

DSPAM_USE_PROCMAIL?=	YES

.if defined(USE_MYSQL)
.include		"../../databases/mysql-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv \
			--with-mysql-includes=${PREFIX}/include/mysql \
			--with-mysql-libraries=${PREFIX}/lib/mysql
MESSAGE_SUBST+=		MYSQL=""
PLIST_SUBST+=		DB4="@comment "
PLIST_SUBST+=		MYSQL=""
.else
.include		"../../databases/db4/buildlink3.mk"
DEPENDS=		db4>=4.2:../../databases/db4
CONFIGURE_ARGS+=	--with-db4-includes=${PREFIX}/include/db4
PLIST_SUBST+=		DB4=""
PLIST_SUBST+=		MYSQL="@comment "
MESSAGE_SUBST+=		MYSQL="@comment "
.endif

.if defined(DSPAM_USE_PROCMAIL)
RUN_DEPENDS=		procmail>=3.22:../../mail/procmail
CONFIGURE_ARGS+=	--with-local-delivery-agent='${PREFIX}/bin/procmail $u'
DSPAM_USE_SGID?=	YES
.elif defined(DSPAM_USE_MAILDROP)
RUN_DEPENDS=		maildrop>=1.3.9:../../mail/maildrop
CONFIGURE_ARGS+=	--with-local-delivery-agent='${PREFIX}/bin/maildrop $u'
DSPAM_USE_SGID?=	YES
.elif defined(DSPAM_USE_MAILLOCAL)
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/libexec/mail.local $u'
.else
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/libexec/mail.local $u'
CONFIGURE_ARGS+=	--enable-delivery-to-stdout
DSPAM_SPAM_DELIVERY?=	YES
.endif

.if defined(DSPAM_USE_SGID)
CONFIGURE_ARGS+=	--with-dspam-mode=2511
.endif

.if defined(DSPAM_SPAM_DELIVERY)
CONFIGURE_ARGS+=	--enable-spam-delivery
.endif

.if defined(DSPAM_CHI_SQUARE)
CONFIGURE_ARGS+=	--enable-chi-square
.endif

.if defined(DSPAM_SIGNATURE_ATTACHMENTS)
CONFIGURE_ARGS+=	--enable-signature-attachments
.endif

.if defined(DSPAM_HOMEDIR_DOTFILES)
CONFIGURE_ARGS+=	--enable-homedir-dotfiles
CONFIGURE_ARGS+=	--enable-opt-in
.endif

.if defined(DSPAM_SOURCE_ADDRESS_TRACKING)
CONFIGURE_ARGS+=	--enable-source-address-tracking
.endif

post-install:
.if defined(USE_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/tools.mysql_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mysql.data ${EXAMPLESDIR}
.endif
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}

.include "../../mk/bsd.pkg.mk"
