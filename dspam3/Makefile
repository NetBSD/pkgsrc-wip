# $NetBSD: Makefile,v 1.12 2004/06/16 05:10:33 xtraeme Exp $
#

DISTNAME=	dspam-3.0.0
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nuclearelephant.com/projects/dspam/
COMMENT=	Extremely scalable and statistical hybrid anti-spam filter

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

REPLACE_PERL=		tools/dspam_genaliases.in \
			tools/dspam_corpus.in

PKGCONFIG_OVERRIDE+=	dspam.pc.in

BDB_ACCEPTED=		db4 db3

BUILD_DEFS+=		DSPAM_DELIVERY_AGENT
BUILD_DEFS+=		DSPAM_HOME
BUILD_DEFS+=		DSPAM_STORAGE_DRIVER
BUILD_DEFS+=		DSPAM_SIGNATURE_LIFE
BUILD_DEFS+=		DSPAM_SIGNATURE_ATTACHMENTS
BUILD_DEFS+=		DSPAM_LARGESCALE
BUILD_DEFS+=		DSPAM_USE_WEBMAIL
BUILD_DEFS+=		DSPAM_HOMEDIR_DOTFILES
BUILD_DEFS+=		DSPAM_USER DSPAM_GROUP
BUILD_DEFS+=		DSPAM_BINMODE

DSPAM_DELIVERY_AGENT?=		procmail
DSPAM_DELIVERY_AGENT_ARGS?=	# empty

DSPAM_HOME?=		${VARBASE}/dspam
DSPAM_STORAGE_DRIVER?=	${BDB_TYPE}
DSPAM_SIGNATURE_LIFE?=	15

DSPAM_BINMODE?=		4511
DSPAM_USER?=		dspam
DSPAM_GROUP?=		dspam
PKG_GROUPS=             ${DSPAM_GROUP}
PKG_USERS=              ${DSPAM_GROUP}:${DSPAM_USER}

# Default options
CONFIGURE_ARGS+=	--enable-client-compression
CONFIGURE_ARGS+=	--enable-robinson
CONFIGURE_ARGS+=	--enable-chi-square
CONFIGURE_ARGS+=	--enable-robinson-pvalues
CONFIGURE_ARGS+=	--with-signature-life=${DSPAM_SIGNATURE_LIFE}
CONFIGURE_ARGS+=	--with-dspam-home-owner=${DSPAM_USER}		\
			--with-dspam-home-group=${DSPAM_GROUP}		\
			--with-dspam-owner=${DSPAM_USER}		\
			--with-dspam-group=${DSPAM_GROUP}		\
			--with-dspam-mode=${DSPAM_BINMODE}

.include "../../mk/bsd.prefs.mk"

#
# Possible: procmail, maildrop or custom
# Default: procmail
#
.if !empty(DSPAM_DELIVERY_AGENT:Mprocmail)
BUILD_DEPENDS+=		procmail-[0-9]*:../../mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent="${LOCALBASE}/bin/procmail"
.elif !empty(DSPAM_DELIVERY_AGENT:Mmaildrop)
BUILD_DEPENDS+=		maildrop-[0-9]*:../../mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent="${LOCALBASE}/bin/maildrop"
.elif !empty(DSPAM_DELIVERY_AGENT:Mcustom)
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_ARGS:Q}
.endif

#
# Possible: mysql, pgsql, db3 or db4
# Default: db3/db4
#
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql)
.  include "../../databases/mysql4-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv
.elif !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
.  include "../../databases/postgresql74-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv
.elif !empty(DSPAM_STORAGE_DRIVER:M${BDB_TYPE})
CONFIGURE_ARGS+=	--with-storage-driver=lib${BDB_TYPE}_drv
.endif

#
# Use of home directory dot file for opt-in/opt-out
#
.if defined(DSPAM_HOMEDIR_DOTFILES) && \
    !empty(DSPAM_HOMEDIR_DOTFILES:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-homedir-dotfiles
.endif

.if defined(DSPAM_USE_WEBMAIL) && \
    !empty(DSPAM_USE_WEBMAIL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-webmail
.endif

.if defined(DSPAM_SIGNATURE_ATTACHMENTS) && \
    !empty(DSPAM_SIGNATURE_ATTACHMENTS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-signature-attachments
.endif

.if defined(DSPAM_LARGESCALE) && !empty(DSPAM_LARGESCALE:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-large-scale
.endif

INSTALLATION_DIRS=	share/doc/${PKGBASE} \
			share/${PKGBASE}/txt share/${PKGBASE}/cgi

post-install:
.for d in txt cgi
	cd ${WRKSRC}/${d} && ${PAX} -rwppm '-s|.*/Makefile.*$$||' \
		. ${PREFIX}/share/${PKGBASE}/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/RE* ${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
