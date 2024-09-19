#! @SH@

BINDARGS="-H $(scepconf -f @PKG_SYSCONFDIR@/openscep.cnf ldap ldapuri)
	  -x -D $(scepconf -f @PKG_SYSCONFDIR@/openscep.cnf ldap binddn)
	  -w $(scepconf -f @PKG_SYSCONFDIR@/openscep.cnf ldap bindpw)"

op="$1"; shift

case "$op" in
ls)
# just dumps the whole database
    ldapsearch $BINDARGS -b $(scepconf -f @PKG_SYSCONFDIR@/openscep.cnf ldap ldapbase) "$@"
;;

add)
# provide ldif at stdin.  example ldif:

#dn: unstructuredName=device-hostname.example.org,dc=example,dc=org
#changetype: add
#objectclass: top
#objectclass: sCEPClient
#objectclass: device
#unstructuredName: device-hostname.example.org
#cn: device-hostname.example.org

    ldapmodify $BINDARGS "$@"
;;

rm)
# provide DN at stdin
    ldapdelete $BINDARGS "$@"
;;
esac
