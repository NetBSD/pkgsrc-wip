PKGREVISION=		2

.include "options.mk"

PLIST_SUBST+=		BAREOS_DB=${BAREOS_DB}
MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}


# For make_catalog_backup.pl.in.
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--with-dir-group=${BAREOS_GROUP}
CONFIGURE_ARGS+=	--with-dir-user=${BAREOS_DIR_USER}
CONFIGURE_ARGS+=	--with-sd-group=${BAREOS_GROUP}
CONFIGURE_ARGS+=	--with-sd-user=${BAREOS_SD_USER}

OWN_DIRS_PERMS+=	${BAREOS_WORKINGDIR} ${ROOT_USER} ${BAREOS_GROUP} 770

PKG_USERS=		${BAREOS_DIR_USER}:${BAREOS_GROUP}
PKG_USERS+=		${BAREOS_SD_USER}:${BAREOS_GROUP}
PKG_GROUPS=		${BAREOS_GROUP}

#CONF_FILES+=		${EXAMPLESDIR}/bareos-fd.conf ${PKG_SYSCONFDIR}/bareos-fd.conf
#CONF_FILES+=		${EXAMPLESDIR}/bconsole.conf ${PKG_SYSCONFDIR}/bconsole.conf
#CONF_FILES+=		${EXAMPLESDIR}/bareos-dir.conf ${PKG_SYSCONFDIR}/bareos-dir.conf
#CONF_FILES+=		${EXAMPLESDIR}/bareos-sd.conf ${PKG_SYSCONFDIR}/bareos-sd.conf

RCD_SCRIPTS=		bareos bareos-dir bareos-sd bareos-fd

REPLACE_PERL+=		src/cats/make_catalog_backup.pl.in

.include "Makefile.common"

.if !empty(USE_DESTDIR:M[Yy][Ee][Ss])
INSTALL_MAKE_FLAGS+=	dir_user= dir_group= sd_group=
.endif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/chio-changer \
		${DESTDIR}${PREFIX}/libexec/bareos/

.include "../../mk/bsd.pkg.mk"
